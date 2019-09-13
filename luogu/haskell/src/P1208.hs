module P1208 where

import Data.List

type Price = (Int, Int)

minCost' :: Int -> [Price] -> Int
minCost' 0 _ = 0
minCost' need ((price, count):prices) = if need <= count then price * need else 
    price * count + minCost' (need - count) prices

minCost :: Int -> [Price] -> Int
minCost need prices = minCost' need $ sortBy (\(a, _) (b, _) -> compare a b) prices

readLine :: (Read a) => IO [a]
readLine = map read . words <$> getLine

readData :: Int -> IO [Price]
readData 0 = return []
readData i = do
    [price, count] <- readLine
    remain <- readData $ i - 1

    return $ (price, count) : remain

main :: IO ()
main = do
    [max, n] <- readLine
    prices <- readData n

    print $ minCost max prices

    return ()