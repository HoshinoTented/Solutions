module P1010 where

import Data.Bits

split' :: Int -> Int -> String
split' _ 0 = "0"
split' c i = 
    if current /= 0 then 
        if call == "0" then pow 
        else call ++ "+" ++ pow 
    else call
    where
        pow = if c == 1 then "2" else "2(" ++ split c ++ ")"
        call = split' (c + 1) remain
        current = i .&. 1
        remain = i `shiftR` 1

split :: Int -> String
split = split' 0

main :: IO ()
main = do
    i <- read <$> getLine

    putStrLn $ split i

    return ()