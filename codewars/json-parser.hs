module JSON.Parser  where

import JSON.Parser.Preloaded (Value(..))
import Data.Char (isDigit)

type NumberString = (String, String)

parseString :: String -> String -> (String, Maybe Value)
parseString [] ('"':'"':str) = (str, Just $ String "")
parseString [] ('"':c:str) =  parseString [c] str
parseString s ('"':str) = (str, Just $ String $ reverse s)
parseString s (c:str) =  parseString (c:s) str

parseNumber' :: String -> Maybe (Maybe NumberString, String)
parseNumber' [] = Nothing
parseNumber' 

parseNumber :: String -> (Maybe Value, String)
parseNumber = (\(a, b) -> (if null a then Nothing else Just $ Number $ read a, b)) . parseNumber' 

parseObject :: String -> Maybe Value
parseObject ms str = undefined

parse :: String -> Maybe Value
parse = undefined
