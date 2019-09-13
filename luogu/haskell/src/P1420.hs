module P1420 where

findIt' :: [Int] -> [Int] -> [Int] -> Int
findIt' max ms [] = length $ if length max >= length ms then max else ms
findIt' max [] (x:xs) = findIt' max [x] xs
findIt' max ms@(m:_) (x:xs) = if x - m == 1 then findIt' max (x : ms) xs else
  if length max > length ms then findIt' max [x] xs else
    findIt' ms [x] xs

findIt :: [Int] -> Int
findIt = findIt' [] []

main :: IO ()
main = do
  _ <- getLine
  xs <- (map read . words) <$> getLine
  
  print $ findIt xs
