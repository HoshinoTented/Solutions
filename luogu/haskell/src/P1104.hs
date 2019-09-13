module P1104 where

import Data.List

data Student = Student {
  sName :: String,
  sYear :: Int,
  sMonth :: Int,
  sDay :: Int
  } deriving (Show, Eq)

instance Ord Student where
  compare s0 s1 = let
    cYear = compare (sYear s1) (sYear s0)
    cMonth = compare (sMonth s1) (sMonth s0)
    cDay = compare (sDay s1) (sDay s0) in
    if cYear /= EQ then cYear else
      if cMonth /= EQ then cMonth else
        if cDay /= EQ then cDay else EQ

readLines :: Int -> IO [Student]
readLines 0 = return []
readLines n = do
  [name, year, month, day] <- words <$> getLine

  ((Student name (read year) (read month) (read day)):) <$> readLines (n - 1)
    
main :: IO ()
main = do
  n <- read <$> getLine :: IO Int
  ss <- readLines n

  let sorted = sort ss in foldr (\x l -> l >>= (const $ putStrLn $ sName x)) (return ()) sorted

  return ()
  
