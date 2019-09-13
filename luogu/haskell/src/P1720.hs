module P1720 where

fibNext :: (Int, Int) -> (Int, Int)
fibNext (a, b) = (b, a + b)

fib :: Int -> Int
fib n = fst (iterate fibNext (0, 1) !! n)

main :: IO ()
main = do
  n <- read <$> getLine :: IO Int
  putStrLn $ show (fib n) ++ ".00"

  return ()
