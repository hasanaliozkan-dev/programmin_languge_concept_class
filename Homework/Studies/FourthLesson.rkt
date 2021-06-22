;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname FourthLesson) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))


"Trees"
(define firsttree (list 1 '() '()))
firsttree

(define secondtree (list 42351
                         (list 2 (
                                  list 332 '() '()) '())
                         (list 3 (
                                  list 4 '() '()) '() )
;                         )
  )
secondtree

(define (rootoftree tree) (car tree))

(rootoftree secondtree)

(define (addallelemintree tree)
  (if (empty? tree)
      0
      (+ (first tree)
         (addallelemintree (first (rest tree)))
         (addallelemintree (first (rest(rest tree))))
         )
      )
  )

(addallelemintree secondtree)






(define (root tree) (first tree))
(define (left tree) (first(rest tree)))
(define (right tree) (first(rest(rest tree))))
(define (max2 a b) (if (> a b) a b))
(define (max3 a b c)  (max2 (max2 a b) (max2 a c)))

(define (maxintree tree) (if (empty? tree)
                             0
                             (max3 (root tree)
                                   (maxintree(left tree))
                                   (maxintree(right tree)))))

(maxintree secondtree)

(define (add a b)
  (if(and (not (number? a)) (not (number? b)))
     (string-append a b)
     (+ a b)))
(add 3 4)
(add "ali" "ali")
(add "3" "4")
(add "ali" " ali")
(if #false  'true 'false)



