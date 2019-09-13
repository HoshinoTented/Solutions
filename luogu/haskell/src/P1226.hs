module P1226 where

import Data.Word
import Data.Bits

type Long = Word64

pow' :: Long -> Long -> Long -> Long -> Long
pow' ans _ 0 p = ans `mod` p
pow' ans base b p = (if b .&. 1 == 1 then pow' $ ans * base `mod` p else pow' ans) (base * base `mod` p) (b `shiftR` 1)  p

pow :: Long -> Long -> Long -> Long
pow = pow' 1

main :: IO ()
main = do
    [a, b, p] <- map read . words <$> getLine

    putStrLn $ show a ++ "^" ++ show b ++ " mod " ++ show p ++ "=" ++ (show $ pow a b p)

    return ()   