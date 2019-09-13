-- TODO
module P1079 where

import Data.Char

main :: String -> String -> String
main k d = undefined

decode :: Char -> Char -> Char
decode e k = if isUpper e then decoded else toLower decoded
  where
    decoded = chr $ ((ord $ toUpper e) - (ord $ toUpper k) + 26) `mod` 26 + (ord 'A')
