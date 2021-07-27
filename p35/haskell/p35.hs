main = print [x | x <- primes 100000, circular x]

primes :: Integral a => a -> [a]
primes 2 = [2]
primes n = 2:[i | i<- [3,5..n], all (\k -> (mod i k /= 0)) (primes $ isqrt i)]

isqrt x = truncate $ sqrt $ fromIntegral x

circular :: Integer -> Bool
circular x = all prime (map (digitsToNum) (rotations x))

circular1 x = all prime (rotations1 x)

digits 0 = []
digits x = digits (x `div` 10) ++ [x`mod`10]

--prime :: Integer -> Bool
prime x = null [y | y <- [2..x`div`2], x`mod`y == 0]

rotations x = let d = digits x in
                  take (length d) (iterate rotate d)

rotations1 x = take (length $ show x) (iterate rotateNum x)

rotateNum x = ((x`mod`10)*10^((length $ show x)-1))+(x`div`10)

rotate [] = []
rotate (x:xs) = xs ++ [x]

digitsToNum xs = digitsToNum' 0 xs

digitsToNum' y [] = y
digitsToNum' y (x:xs) = digitsToNum' (10*y+x) xs
