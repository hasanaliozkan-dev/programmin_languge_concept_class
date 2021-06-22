#lang br/quicklang

; beautiful racket funstacker chapter with
; some modifications


(define stack empty)
;(define parens (list))

(define (pop-stack!)
  (define arg 0)
  (if (not (empty? stack))
      (set! arg (first stack))
      (displayln "empty stack"))
  (set! stack (rest stack))
  arg)

(define (clear-stack!)
  (set! stack (remove stack stack))
  stack)
(define (push-stack! arg)
  (set! stack (cons arg stack)))

; parser

(define (read-syntax path port)
  (define src-lines (port->lines port))
  (define src-datums (my-format-datums src-lines))
  ;(define src-datums (format-datums '~a src-lines)) ; original line
  (displayln src-datums) ; debugging
  (define module-datum `(module funstacker-mod "den.rkt"
                          (handle ,@src-datums)))
  (displayln module-datum) ; debugging
  (datum->syntax #f module-datum))

(provide read-syntax)

(define (my-format-datum . args)
  `(handle ,@args))

(define (my-format-datums lines)
  (for/list ((l lines)
             #:unless (string=? "" l))
    (apply my-format-datum (string-split l))))








; expander
(define-macro (funstacker-module-begin HANDLE-EXPR ...)
  #'(#%module-begin
     HANDLE-EXPR ...
     (display "Result: ")
     (displayln (pop-stack!))))

(provide (rename-out (funstacker-module-begin #%module-begin)))

(define (string-numeric? chr) (number? (string->number chr))) ;casting character type to number.  

(define (handle arg1 arg2 arg)
  (display "arg")
  (writeln arg) ; debugging
  (for ([chr arg])
    (cond
      ((string-numeric? chr) (push-stack! (string->number chr)))
      ;((or (equal? "(" arg) (string=? ")" arg) ) (push-parens! arg))
      ((or (equal? + arg) (equal? - arg))
       (define op-result (calculate-add-subb arg))
       (push-stack! op-result))
      ((or (equal? * arg) (equal? / arg))
       (define op-result (calculate-mult-div arg))
       (push-stack! op-result)))))


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
(provide handle)

