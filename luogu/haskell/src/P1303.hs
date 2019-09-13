module P1303 where

main :: IO ()
main = do
  a <- read <$> getLine :: IO Integer
  b <- read <$> getLine :: IO Integer

  print $ (a * b)
