-- note: nub in Data.List does this (except it keeps the first element rather than the last)

unique [] = []
unique (x:xs) = if (x `elem` xs) then unique xs else x:unique xs
