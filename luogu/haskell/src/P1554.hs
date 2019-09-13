module P1554 where

import Data.List

-- TODO MLE

count' :: Int -> Int -> Int -> Int -> Int -> Int -> Int -> Int -> Int -> Int -> String -> [Int]
count' zero one two three four five six seven eight nine [] = [zero, one, two, three, four, five, six, seven, eight, nine]
count' zero one two three four five six seven eight nine ('0':str) = count' (zero + 1) one two three four five six seven eight nine str
count' zero one two three four five six seven eight nine ('1':str) = count' zero (one + 1) two three four five six seven eight nine str
count' zero one two three four five six seven eight nine ('2':str) = count' zero one (two + 1) three four five six seven eight nine str
count' zero one two three four five six seven eight nine ('3':str) = count' zero one two (three + 1) four five six seven eight nine str
count' zero one two three four five six seven eight nine ('4':str) = count' zero one two three (four + 1) five six seven eight nine str
count' zero one two three four five six seven eight nine ('5':str) = count' zero one two three four (five + 1) six seven eight nine str
count' zero one two three four five six seven eight nine ('6':str) = count' zero one two three four five (six + 1) seven eight nine str
count' zero one two three four five six seven eight nine ('7':str) = count' zero one two three four five six (seven + 1) eight nine str
count' zero one two three four five six seven eight nine ('8':str) = count' zero one two three four five six seven (eight + 1) nine str
count' zero one two three four five six seven eight nine ('9':str) = count' zero one two three four five six seven eight (nine + 1) str


count :: Int -> Int -> [Int]
count begin end = count' 0 0 0 0 0 0 0 0 0 0 $ foldl' (\l x -> show x ++ l) [] [begin..end]

main :: IO ()
main = do
  [begin, end] <- (map read . words) <$> getLine
  
  putStrLn $ foldr (\x l -> show x ++ " " ++ l) [] $ count begin end

  return ()
