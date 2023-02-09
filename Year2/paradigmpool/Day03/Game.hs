{-
-- EPITECH PROJECT, 2023
-- B-PDG-300-REN-3-1-PDGD03-mael.becel
-- File description:
-- Haskell
-}

-- Task 01, 02
data Item = Sword | Bow | MagicWand deriving (Eq)

-- Task 03
instance Show Item where
    show item = do
        case item of
            Sword -> "sword"
            Bow -> "bow"
            MagicWand -> "magic wand"

-- Task 04
data Mob = Mummy | Skeleton Item | Witch (Maybe Item) deriving (Eq)

-- Task 05
createMummy :: Mob
createMummy = Mummy
createArcher :: Mob -- a Skeleton holding a Bow
createArcher = Skeleton Bow
createKnight :: Mob -- a Skeleton holding a Sword
createKnight = Skeleton Sword
createWitch :: Mob -- a Witch holding Nothing
createWitch = Witch Nothing
createSorceress :: Mob -- a Witch holding a MagicWand
createSorceress = Witch (Just MagicWand)

-- Task 06
create :: String -> Maybe Mob
create [] = Nothing
create "mummy" = Just Mummy
create "doomed archer" = Just (Skeleton Bow)
create "dead knight" = Just (Skeleton Sword)
create "witch" = Just (Witch Nothing)
create "sorceress" = Just (Witch (Just MagicWand))
create mob = Nothing

-- Task 07
equip :: Item -> Mob -> Maybe Mob
equip _ Mummy = Nothing
equip newitem (Witch item) = Just (Witch (Just newitem))
equip newitem (Skeleton item) = Just (Skeleton newitem)

-- Task 08
instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton (item)) = ("skeleton holding a " ++ show item)
    show (Witch Nothing) = "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just (item))) = ("witch holding a " ++ show item)

-- Task 09
class HasItem obj where
    getItem :: obj -> Maybe Item
    hasItem :: obj -> Bool
    hasItem obj = case getItem obj of
        Nothing -> False
        Just _ -> True

-- Task 10
instance HasItem Mob where
    getItem Mummy = Nothing
    getItem (Skeleton item) = Just item
    getItem (Witch (Just item)) = Just item
    getItem (Witch Nothing) = Nothing