// Test des paramètres string - log

func void log(str niveau, str message) {
    print("===================");
    print(niveau);
    print(message);
    print("===================");
}

func void info(str msg) {
    log("INFO", msg);
}

func void error(str msg) {
    log("ERROR", msg);
}

info("Démarrage du programme");
error("Une erreur est survenue");
info("Fin du programme");
