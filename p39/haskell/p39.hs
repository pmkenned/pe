module Main where

main = print $ let m = maximum list
                   list = map length [x p | p <- [1..1000]] in
                   find m list

find x [] = []
find x ys = find' x 0 ys

find' x n [] = []
find' x n (y:ys) = if x==y then (n:find' x (n+1) ys) else find' x (n+1) ys

x p = [ [a,b,c] |
        a <- [1..p/4],
        b <- [a+1..(p-a)/2],
        c <- [p-(a+b)],
        a<b, b<c, right a b c, p == a+b+c]

right a b c = c^2 == a^2 + b^2
