module P1424 (practice)  where

-- From -> End -> Length
practice :: Int -> Int -> Int
practice f e = practice' 0 0 f e

practiceLength :: Int -> Int
practiceLength 6 = 0
practiceLength 7 = 0
practiceLength _ = 150 + 100

nextDay :: Int -> Int
nextDay 7 = 1
nextDay a = a + 1

-- Iterator -> Length -> From (Day) -> End -> Result Length
practice' :: Int -> Int -> Int -> Int -> Int
practice' i l f e
  | i < e = practice' (i + 1) (l + practiceLength i) (nextDay f) e
  | otherwise = l

