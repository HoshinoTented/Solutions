module U51941 where

main :: String -> Int
main = length . filter (/= ' ')
