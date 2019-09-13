module P2141 where

sums :: [Int] -> [Int]
sums [] = []
sums (x:xs) = map (+x) xs ++ sums xs

contains :: [Int] -> Int
contains xs = let sum = sums xs in
    foldr (\x s -> if elem x sum then 1 + s else s) 0 xs

main :: IO ()
main = do
    getLine
    xs <- map read . words <$> getLine

    print $ contains xs