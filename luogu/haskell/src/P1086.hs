module P1086 where

import Data.List

data Pos = Pos {
  posX :: Int,
  posY :: Int,
  posValue:: Int
  } deriving (Show)

parseLine :: Int -> Int -> Int -> [String] -> [Pos]
parseLine _ _ _ [] = []
parseLine x n m (s:ss) = if n == m then [] else
  let v = read s in
    if v == 0 then call else
      Pos x n v : call
  where
    call = parseLine x (n + 1) m ss

readLines :: Int -> Int -> Int -> IO [Pos]
readLines y n m = if n == m then return [] else
  ((++) <$> ((parseLine n 0 y) . words <$> getLine)) <*> readLines y (n + 1) m

timedOut :: Pos -> Int -> Bool
timedOut p tl = posX p + 1 > tl - 1

pick :: Pos -> [Pos] -> Int -> Int
pick p [] tl = if timedOut p tl then 0 else posValue p
pick p (t:ps) tl = if timedOut p tl then 0 else
  posValue p + (pick t ps (moveTo - 1))
  where
    moveTo = tl - ((abs (posX p - posX t)) + (abs (posY p - posY t)))

main :: IO ()
main = do
  [m, n, tl] <- (map read . words) <$> getLine :: IO [Int]
  ls <- readLines n 0 m

  let (p:ps) = sortBy (\a b -> if posValue a > posValue b then LT else GT) ls in print $ pick p ps (tl - posX p - 1)

  return ()
