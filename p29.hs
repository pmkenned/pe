import Data.List

main = print $ length $ nub x

x = [(a :: Integer)^(b :: Integer) | a <- [2..100], b <- [2..100]]
