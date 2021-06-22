;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname FirstLesson) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))

"1) prefix notation"
(+ 3 4)
(+ (+ 2 4) (+ 4 8))
(+ 2 2)
(* 3 3)
(- 4 2)
(/ 6 2)

(define a (+ 3 4))
a
(+ (* 5 5) (+ (* 3 (/ 12 4)) 4))
(+ 25  13)

"pisagor with prefix notation"
(define x 3)
(define y 4)
(define z (sqrt (+ (* x x) (* y y))))
x
y
z
(sin 45)
(cos 45)
(define tanfourtyfive (/(sin 45) (cos 45)))
"tan 45"
tanfourtyfive
(tan 45)
(sin 0)
"2) string operations"
"hasan ali özkan"
(define name "ali")
(define lastname "özkan")
name
lastname

(define full-name(string-append name " " lastname))
full-name

(define lengthofmyfullname (string-length full-name))
lengthofmyfullname

(define fourthitem (string-ith full-name 4))
fourthitem

(define stringx "3")
x
(number->string x)

(string->number stringx)
"#f means false"
(string->number   "hello-world")

"3) logical operators"

#false
#true
(or #false #true)
