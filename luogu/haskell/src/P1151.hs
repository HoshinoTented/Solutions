module P1151 where

-- K -> Target -> Result
check :: Int -> String -> Bool
check k [a, b, c, d, e] = sub1 && sub2 && sub3
  where
    sub1 = read (a : b : [c]) `mod` k == 0
    sub2 = read (b : c : [d]) `mod` k == 0
    sub3 = read (c : d : [e]) `mod` k == 0

-- Tmp -> K (Final) -> Begin -> End -> IO Monad
find' :: [Int] -> Int -> Int -> Int -> [Int]
find' xs k b e = if b == e then xs else let s = show b in
  find' (if check k s then b : xs else xs) k (b + 1) e

find :: Int -> [Int]
find k = find' [] k 10000 30001

print' :: [Int] -> IO ()
print' [] = return ()
print' (x:xs) = do
  putStrLn $ show x
  print' xs

main :: IO ()
main = do
  k <- read <$> getLine

  let xs = find k in
    if length xs == 0 then putStrLn "No" else
      print' $ reverse xs
