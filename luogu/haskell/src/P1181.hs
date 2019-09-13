module P1181 where

split' :: Int -> Int -> [Int] -> Int
split' 0 _ [] = 0
split' _ _ [] = 1
split' sum max (x:xs)
    | sum + x > max = 1 + split' x max xs
    | otherwise = split' (sum + x) max xs

split :: Int -> [Int] -> Int
split = split' 0

main :: IO ()
main = do
    [n, max] <- map read . words <$> getLine
    xs <- map read . words <$> getLine

    print $ split max xs

    return ()