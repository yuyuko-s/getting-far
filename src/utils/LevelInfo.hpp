enum class LevelDifficulty {
    NA, Auto, Easy,
    Normal, Hard, Harder,
    Insane, EasyDemon, MediumDemon,
    HardDemon, InsaneDemon, ExtremeDemon
};

class LevelInfo {
public:
	static LevelDifficulty getLevelDifficulty(GJGameLevel* level);
	static std::string getDifficultyImage(LevelDifficulty difficulty);
    
};
