#lang br/quicklang
(provide read-syntax
         (rename-out (postfix-mod-begin #%module-begin))
         handle
         + * - /)

;
; helper functions
;

(define stack (list))
(define parens (list))

(define (pop-stack!)
  (define arg (first stack))
  (set! stack (rest stack))
  arg)

(define (clear-stack!)
  (set! stack (remove stack stack))
  stack)
(define (push-stack! arg)
  (set! stack (cons arg stack)))
(define (push-parens! arg)
  (set! parens (cons arg parens)))

;
; Racket Reader
; read-syntax runs when execute your language.
; Turns language into Racket lisp code.
;
; replace language with:
; (module postfix "postfix.rkt"
; (handle 3)
; (handle 2)
; (handle +))
;
(define (read-syntax path port)
  (define src-lines (port->lines port))
    (define src-datums (format-datums "(handle ~a)" src-lines))
    (writeln src-datums) ; debugging
    (define module-datum `(module postfix "PostfixV2.rkt"
                            ,@src-datums))
    (writeln module-datum) ; debugging
    (datum->syntax #f module-datum))

(define (string->datum str)
  ;; str => "+"
  ;; (read (open )) => '+
  (unless (string=? "" str)
    (read (open-input-string str))))

(define (format-datums template lines)
  ;; lines => (" " "3 2 +" "4 5 *")

  (writeln lines) ; debugging

  ;; map => (() ("3" "2" "+") ("4" "5" "*"))
  ;; flatten => ("3" "2" "+" "4" "5" "*")
  (define char-strs (flatten (map string-split lines)))

  ;(writeln char-strs) ; debugging

  ;; format => ("(handle 3)" "(handle 2)" ... )
  (define formatted-strs (map (λ (x) (format template x))
                              char-strs))

  ;(writeln formatted-strs) ; debugging

  ;; strings->datum => '((handle 3) (handle 2) ... )
  (map string->datum formatted-strs))

;
; Racket Expander
; Converts our (module ...) function from the reader to
; (#%module-begin ...) and runs the code inside.
;
; e.g.
; (#%module-begin
; (handle 3)
; (handle 2)
; (handle +)
; (display ("Result: ")
; (displayln (pop-stack!)))
;
(define-macro (postfix-mod-begin HANDLE-EXPR ...)
  #'(#%module-begin
     HANDLE-EXPR ...
     (display "Result: ")
     (displayln (pop-stack!))))

;
; These are the helpers functions/macros that will
; get executed when our module is loaded and ran from
; (#%module-begin ...)
;

(define (handle arg)
  ; (writeln arg) ; debugging
  (cond
    ((number? arg) (push-stack! arg))
    ;((or (equal? "(" arg) (string=? ")" arg) ) (push-parens! arg))
    ((or (equal? + arg) (equal? - arg))
     (define op-result (calculate-add-subb arg))
     (push-stack! op-result))
    ((or (equal? * arg) (equal? / arg))
     (define op-result (calculate-mult-div arg))
     (push-stack! op-result))))


(define (calculate-add-subb arg)
  (define result 0)
  (for ([item stack])
    (set! result (arg result (pop-stack!))))
  ;(displayln stack)
  ;(set! stack(clear-stack!))
  result)

(define (calculate-mult-div arg)
  (define result 1)
  (for ([item stack])
    (set! result (arg result (pop-stack!))))
  result)