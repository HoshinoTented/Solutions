module P1824 where

import Data.List

-- Ask :: Request -> Last -> N -> C -> Rooms -> QAQ?
ask :: Int -> Int -> Int -> Int -> [Int] -> Bool
ask _ _ _ 0 _ = True
ask _ _ _ _ [] = False
ask x last n c (room:rooms) = if room - last >= x then ask x room n (c - 1) rooms 
    else ask x last n c rooms

-- Binary Answer :: Left -> Right -> Answer -> N -> C -> Rooms -> Final Answer
binaryAns :: Int -> Int -> Int -> Int -> Int -> [Int] -> Int
binaryAns left right ans n c rooms = if left > right then ans else
    let mid = (left + right) `div` 2 in
        if ask' mid then binaryAns (mid + 1) right mid n c rooms 
        else binaryAns left (mid - 1) ans n c rooms
    where
        ask' x = ask x (head rooms) n (c - 1) rooms

-- Read  Data -> Iterator -> Biggest -> Result
readData :: Int -> IO [Int]
readData 0 = return []
readData n = do
    i <- read <$> getLine

    readData (n - 1) >>= \xs -> return $ i : xs

main :: IO ()
main = do
    [n, c] <- map read . words <$> getLine :: IO [Int]
    rooms <- sort <$> readData n

    print $ binaryAns 0 (last rooms - head rooms) 0 n c rooms

    return ()