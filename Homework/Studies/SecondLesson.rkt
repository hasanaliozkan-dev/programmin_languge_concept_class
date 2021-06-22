;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname SecondLesson) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))

;It is a line comment.
"1)Conditionals"
(define a 1)
(define b 1)
(define red "red")
(define green "green")
(define blue "blue")
(define currcol "blue")
(if (= a b)
    (display "equal\n")
    (if (< a b)
        (display "a less than b\n")

    (display "a greater than b\n")))

(cond [(= a b) (display "equal\n" )]
      [(< a b) (display "a less than b\n" )]
      [(> a b) (display  "a greater than b\n")])

(if (string=? red currcol)
    (display "curr col isred\n")
    (if (string=? blue currcol)
        (display "curr col is blue\n")
    (display "curr col is green\n")
    )
)

(cond [(string=? currcol red) (display "curr col is red\n")]
      [(string=? currcol blue) (display "curr col is blue\n")]
      [(string=? currcol green) (display "curr col is gree\n")])

"2)Functions"

(define(f x ) x)
(define (square x)
  (* x  x)
)
(square 5)

(define (distancefromorigin x y )
  (sqrt (+ (* x x) (* y y)))
)
(distancefromorigin 3 4)

(define (cvolume h)
  (* h h h)
)
(cvolume 5)

(define (csurface h) (* 6 (* h h )))
(csurface 5)


(define (string-first input)
  (if (string? input)
      (string-ith input 0)
      (display "It is not a string\n")))

(string-first "hasan ali")

(define (string-last input)
  (if (string? input)
      (string-ith input (- (string-length input) 1))
      (display "It is not a string\n"))
)
(string-last "hasan ali")


(define (string-join a b )
  (if (and (string? a) (string? b))
      (string-append a "_" b)
  (display "not a string!\n"))
)
(string-join "4" 2)

(define (letter fst lst signature-name)
  (string-append
    (opening fst)
    "\n\n"
    (body fst lst)
    "\n\n"
    (closing signature-name)))
 
(define (opening fst)
  (string-append "Dear " fst ","))
 
(define (body fst lst)
  (string-append
   "We have discovered that all people with the" "\n"
   "last name " lst " have won our lottery. So, " "\n"
   fst ", " "hurry and pick up your prize."))
 
(define (closing signature-name)
  (string-append
   "Sincerely,"
   "\n\n"
   signature-name
   "\n"))
(display (letter "ali" "özkan" "hasan"))


(define (myapply function a b)
  (function a b)
)

(myapply + 3 5 )


(define (factorial n)
  (if (= n 1)
      1 
  (* n (factorial (- n 1)))
  )
)

(factorial 3)
(factorial 4)
(factorial 5)


(define (fibonacci n)
  (if (= n 0)
      0
      (if (= n 1)
          1
      (+ (fibonacci (- n 1))
         (fibonacci (- n 2)))
      )
  )
)

(fibonacci 0)
(fibonacci 1)
(fibonacci 2)
(fibonacci 3)
(fibonacci 4)
(fibonacci 11)










