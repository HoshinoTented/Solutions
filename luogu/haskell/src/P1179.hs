module P1179 where

count :: Int -> Int
count x = foldr (\x l -> (if x == '2' then (+1) else (+0)) l) 0 $ show x

main :: IO ()
main = do
    [begin, end] <- (map read . words) <$> getLine :: IO [Int]

    print $ foldr (\x l -> count x + l) 0 [begin..end]

    return ()