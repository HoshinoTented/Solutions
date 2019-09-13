module P3954 where

main :: IO ()
main = do
  [a, b, c] <- (map read . words) <$> getLine :: IO [Float]

  print $ round $ a * 0.2 + b * 0.3 + c * 0.5
  
  return ()
