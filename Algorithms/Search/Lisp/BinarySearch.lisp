;;;; Binary Search implemented in ANSI Common Lisp

(defun binary-search (arr l r x)
    (cond
        ((>= r l)
            (let ((mid (+ l (floor (/ (- r l) 2)))))
                (if (eq mid x)
                    mid
                    (if (> (aref arr mid) x)
                        (binary-search arr l (- mid 1) x)
                        (binary-search arr (+ mid 1) r x)))))
        (T
            -1)))

(format t "~d~%" (binary-search #(1 2 3 4 5 6 7 8 9 10) 0 5 2))
