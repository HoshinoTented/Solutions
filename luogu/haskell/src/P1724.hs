module P1724 where

data Position = Position Integer Integer

instance Show Position where
  show (Position x y) = show x ++ ' ' : show y

moveCommand :: Char -> Position
moveCommand 'N' = Position 0 1
moveCommand 'S' = Position 0 (-1)
moveCommand 'E' = Position 1 0
moveCommand 'W' = Position (-1) 0

-- Commands -> Tick -> Position
move :: String -> Int -> Position
move cs t = fullMove `add` subMove
  where
    fullTimes = t `div` length cs
    subTimes = t `mod` length cs
    fullMove = move' cs fullTimes
    subMove = move' (take subTimes cs) subTimes

add :: Position -> Position -> Position
(Position ax ay) `add` (Position bx by) = Position (ax + bx) (ay + by)

times :: Position -> Integer -> Position
(Position ax ay) `times` t = Position (ax * t) (ay * t)

-- Commands -> Times -> Position
move' :: String -> Int -> Position
move' cs t = moveOnce `times` toInteger t
  where
    moveOnce = foldr (\c p -> moveCommand c `add` p) (Position 0 0) cs
