module P1634 where

main :: IO ()
main = do
  [x, n] <- (map read . words) <$> getLine

  print $ round $ (1 + x) ** n
