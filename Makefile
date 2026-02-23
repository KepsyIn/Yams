# Variables
CXX = g++
# Ajout de -Wall -Wextra pour un code plus propre (recommandé en MVC)
CXXFLAGS = -O3 -std=c++17 -Wall -Wextra
INCLUDES = -I./include

# Utilisation de 'find' pour récupérer tous les .cpp dans les sous-dossiers de src
SRCS = $(shell find src -name "*.cpp")
# Transforme la liste des .cpp en .o en gardant la structure des dossiers
OBJS = $(SRCS:.cpp=.o)

TARGET = bin/yams

# Cible par défaut
all: $(TARGET)

# Règle pour construire l'exécutable
$(TARGET): $(OBJS)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

# Règle générique pour construire les objets (.o) à partir des (.cpp)
# Cette règle fonctionne récursivement pour tous les sous-dossiers
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJS)
	rm -rf bin

# Nettoyage complet (objets + binaire)
fclean: clean
	rm -f $(TARGET)

.PHONY: all clean fclean