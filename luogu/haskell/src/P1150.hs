module P1150 where

smoking' :: Int -> Int -> Int -> Int
smoking' _ 0 _ = 0
smoking' i m n = m + smoking' ((m + i) `mod` n) ((m + i) `div` n) n

smoking :: Int -> Int -> Int
smoking = smoking' 0

main :: IO ()
main = do
  [m, n] <- (map read . words) <$> getLine
  
  print $ smoking m n
  
  return ()
  
