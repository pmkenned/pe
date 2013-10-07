module Main where

main :: IO ()
main = print (prime_factors_of 600851475143)

prime_factors_of :: Integer -> [Integer]
prime_factors_of 0 = []
prime_factors_of 1 = []
prime_factors_of n = f : prime_factors_of(n `div` f)
    where f = head $ filter (\d -> n `mod` d == 0) [2..n]
