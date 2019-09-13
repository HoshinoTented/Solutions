module P1957 where
import Data.Char

-- TODO

data Formula = Formula Operator Int Int deriving (Show)
data Operator = Plus | Minus | Times deriving (Show)

type Value = Int

operator :: Char -> Operator
operator 'a' = Plus
operator 'b' = Minus
operator 'c' = Times

-- Inputs -> Results
computes :: [[String]] -> [Value]
computes inputs = undefined

-- Default Operator -> Input -> Result
parse :: Operator -> [[String]] -> [Value]
parse op (x:xs)
  | length x /= 2 = compute (operator $ head $ head x) (drop 1 x) : []
  | otherwise = undefined

-- Operator -> Values -> Result
compute :: Operator -> [String] -> Int
compute op (x:y) = compute' $ Formula op (read x) (read $ head y)

compute' :: Formula -> Value
compute' (Formula Plus a b) = a + b
compute' (Formula Minus a b) = a - b
compute' (Formula Times a b) = a * b
