module Kata.BraceExpansion (expandBraces) where

data ExString = RawString String    -- raw string: "raw string"
  | ExString [ExString]             -- expanded string: "{ex,string}"
  | ExStrings [ExString]            -- expanded strings: "raw str{ing,ange}"
  deriving (Show)

expandBraces' :: ExString -> [String]
expandBraces' (RawString s) = [s]
expandBraces' (ExString xs) = xs >>= expandBraces'
expandBraces' (ExStrings []) = [[]]
expandBraces' (ExStrings (x:xs)) = expandBraces' x >>= (\s -> foldr (\s' l -> (s ++ s') : l) [] $ expandBraces' $ ExStrings xs)

parseRaw :: Bool -> String -> String -> (String, ExString)
parseRaw _ ts [] = ([], RawString $ reverse ts)
parseRaw _ ts xs@('{':_) = (xs, RawString $ reverse ts)
parseRaw _ ts xs@('}':s) = (xs, RawString $ reverse ts)
parseRaw True ts xs@(',':s) = (xs, RawString $ reverse ts)
parseRaw b ts (c:s) = parseRaw b (c:ts) s

parseEx :: [ExString] -> String -> (String, ExString)
parseEx xs ('{':s) = let e = parseExs True [] s in parseEx (snd e : xs) $ fst e
parseEx xs ('}':s) = (s, ExString xs)
parseEx xs (',':s) = parseEx xs ('{':s)

parseExs :: Bool -> [ExString] -> String -> (String, ExString)
parseExs _ ts [] = ([], ExStrings $ reverse ts)
parseExs b ts xs@('{':s) = let ex = parseEx [] xs in parseExs b (snd ex : ts) $ fst ex
parseExs _ ts xs@('}':s) = (xs, ExStrings $ reverse ts)
parseExs True ts xs@(',':s) = (xs, ExStrings $ reverse ts)
parseExs b ts s = let raw = parseRaw b [] s in
  parseExs b (snd raw : ts) $ fst raw

exparse :: String -> ExString
exparse = snd . parseExs False []

expandBraces :: String -> [String]
expandBraces = expandBraces' . exparse
