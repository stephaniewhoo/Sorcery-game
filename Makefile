CXX = g++-5
CXXFLAGS = -std=c++14 -Werror=vla
EXEC = sorcery
OBJECTS = ascii_graphics.o board.o card.o deck.o main.o minion.o player.o ritual.o spell.o enchantment.o textdisplay.o airelem.o apprentice.o auraofpower.o banish.o blizzard.o bonegolem.o darkritual.o disenchant.o earthelem.o enrage.o fireelem.o GiantStre.o haste.o MagicFati.o massum.o novice.o potionsell.o raisedead.o recharge.o Silence.o standstill.o unsummon.o  
DEPENDS = ${OBJECTS.o: .d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
