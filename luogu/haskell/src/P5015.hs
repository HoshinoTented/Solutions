module P5015 where

main :: IO ()
main = do
  ws <- words <$> getLine
  print $ foldr (\x s -> s + length x) 0 ws