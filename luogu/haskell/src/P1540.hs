module P1540 where

-- Unit Size -> Words -> Times
findTimes :: Int -> [Int] -> Int
findTimes s ws = findTimes' 0 [] s ws

-- Times -> Units -> Unit Size -> Words -> Result Times
findTimes' :: Int -> [Int] -> Int -> [Int] -> Int
findTimes' t _ _ [] = t
findTimes' t us s (w:ws)
  | elem w us = findTimes' t us s ws
  | length us /= s = findTimes' (t + 1) (us ++ [w]) s ws
  | otherwise = findTimes' (t + 1) (drop 1 us ++ [w]) s ws
