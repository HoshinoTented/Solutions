module P1019 where

import qualified Data.Vector as V
import           Data.Vector ((!), (//))
import           Control.Applicative ((<|>))

type Graph = V.Vector (V.Vector String)

-- Depth First Search Environment (Graph, Visited, Words)
type DfsEnv = (Graph, V.Vector Int, V.Vector String)

mapNotNull :: (a -> Maybe a) -> [a] -> [a]
mapNotNull _ [] = []
mapNotNull f (x:xs) = case f x of
    Just i -> i : mapNotNull f xs
    Nothing -> mapNotNull f xs

canConnect :: String -> String -> Maybe Int
canConnect a b = 
    foldr (\i m -> if equal i then Just i else m) Nothing [1..minLen] >>= \x -> 
        if x == minLen then Nothing else Just x
    where
        aLen = length a
        bLen = length b
        minLen = min aLen bLen
        equal i = drop (aLen - i) a == take i b

readData :: Int -> IO [String]
readData 0 = return []
readData n = do
    line <- getLine
    rest <- readData $ n - 1

    return $ line : rest 

main :: IO ()
main = do
    -- n <- read <$> getLine
    -- xs <- readData n

    [a, b] <- words <$> getLine

    print $ canConnect a b


    return ()