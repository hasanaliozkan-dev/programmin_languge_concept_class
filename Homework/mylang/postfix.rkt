#lang br/quicklang
(provide read-syntax
(rename-out (postfix-module-begin #%module-begin))
handle)

;; global helpers

(define result 0)

(define stack '())

(define (pop-stack!)
(define arg (first stack))
(set! stack (rest stack))
arg)

(define (push-stack! arg)
(set! stack (cons arg stack)))

;; lang boilerplate

(define (read-syntax path port)
(define src-lines (port->lines port))
(define src-datum (my-format-datums src-lines))
;(displayln src-datum)
(define module-datum `(module postfix-module "postfix.rkt"
,@src-datum))
;(displayln module-datum)
(datum->syntax #f module-datum))

;; parse each character of the first line of input program
(define (my-format-datum src-line)
(for/list ((char src-line)
#:unless (char-blank? char))
; can I fix the number issue in here somehow?
(displayln (char? char))
`(handle ,char)))

;; parse first line of input program
(define (my-format-datums src-lines)
(for/last ((src-line src-lines)
#:unless (string=? "" src-line))
(my-format-datum src-line)))

(define-macro (postfix-module-begin HANDLE-EXPR ...)
#'(#%module-begin
; quote HANDLE-EXPR to see what the input is
HANDLE-EXPR ...
(display "Result: ")
(displayln result)))

(define (handle (arg #f))
(cond
; can't figure out how to convert #\3 to 3
; (char->integer #\3) converts #\3 into ascii value 51
; instead of 3
((char-numeric? arg)
(display "Arg: ")
(displayln arg))
((char=? arg #\+)
(displayln "Add!"))
((char=? arg #\*)
(displayln "Multiply!"))))