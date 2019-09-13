module P1567 where

-- TODO MLE

-- Max -> Continuation Count -> Last Temp -> Days Temp -> New Max
maxContinuation :: Int -> Int -> Int -> [Int] -> Int
maxContinuation max c _ [] = if max < c then c else max
maxContinuation max c l (t:ts) = if
  t > l then maxContinuation max (c + 1) t ts
  else (maxContinuation (if max < c + 1 then c + 1 else max) 0 t ts)

main :: IO ()
main = do
  _ <- getLine
  days <- (map read . words) <$> getLine

  print $ maxContinuation 0 0 0 days

  return ()
