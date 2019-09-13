module P1059 where

import Data.List

main :: IO ()
main = do
    _ <- getLine
    xs <- map read . words <$> getLine :: IO [Int]

    let list = map head $ group $ sort xs

    print $ length list
    putStrLn $ list >>= (\x -> show x ++ " ")

    return ()