module P1025 where

-- TODO TLE #4 #5

count' :: Int -> Int -> Int -> Int
count' _ 0 0 = 1
count' _ _ 0 = 0
count' last n k = foldr (\x l -> l + (c x)) 0 [last..n]
  where
    c x = if last <= x then count' x (n - x) (k - 1) else 0

-- 计算分法 :: N -> K -> 结果
count :: Int -> Int -> Int
-- count 200 5 = 583464
count = count' 1

main :: IO ()
main = do
  [n, k] <- (map read . words) <$> getLine

  print $ count n k
