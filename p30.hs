main = print $ sum list

list = [x | x <- [2..1000000], x == (sum $ map (^5) (digits x))]

digits 0 = []
digits x = (x `mod` 10) : digits (x `div` 10)
