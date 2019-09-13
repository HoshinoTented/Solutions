module P1009 where

main :: IO ()
main = do
  i <- read <$> getLine
  print $ foldr (\x l -> x * (1 + l)) 0 [1..i]
