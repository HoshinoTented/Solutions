module P4413 where

main :: IO ()
main = do
  [r1, s] <- map read . words <$> getLine

  print $ s * 2 - r1
