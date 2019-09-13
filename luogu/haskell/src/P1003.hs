module P1003 where
data Position = Position Int Int deriving (Show)
data Carpet = Carpet Position Int Int deriving (Show)

-- Carpets -> Request position -> CarpetID
request :: [Carpet] -> Position -> Int
request carpets pos = if carpetIds == [] then (-1) else 1 + head carpetIds
  where
    carpetIds = filter (\x -> contains (carpets !! x) pos) $ reverse [0..length carpets - 1]

contains :: Carpet -> Position -> Bool
contains (Carpet (Position x y) h v) (Position reqX reqY) =
  x <= reqX &&
  y <= reqY &&
  x + h >= reqX &&
  y + v >= reqY
