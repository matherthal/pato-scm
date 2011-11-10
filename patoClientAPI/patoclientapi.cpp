#include "patoclientapi.h"
#include "PatoClientException.h"
#include "statusOutput.h"
#include "updateOutput.h"
#include <iostream>
#include<stdlib.h>
#include <string.h>
#include<QString>
#include<QList>
#include<QTextStream>
using namespace std;

PatoClientApi::PatoClientApi() {
}

QList<checkoutOutput> PatoClientApi::checkout(int revision, QString address, QString username, QString password, QString workspace) throw (PatoClientException) {

    QList<checkoutOutput> output;

    //    if (revision < -1) {
    //        throw (PatoClientException("Invalid revision number."));
    //    } else 
    if (address == "") {
        throw (PatoClientException("The checkout command needs an address."));
    } else if (username == "") {
        throw (PatoClientException("The checkout command needs an username."));
    } else if (password == "") {
        throw (PatoClientException("The checkout command needs a password."));
    }
    //    else if (workspace == "") {
    //        throw (PatoClientException("The checkout command needs a workspace."));
    //    }

    return output;
}

QList<logOutput> PatoClientApi::log(QString address, QString username, QString password, QString initialRevision, QString finalRevision) throw (PatoClientException) {



    QList<logOutput> output;

    bool* initial;
    bool* final;


    int initialInt = 0;
    int finalInt = 0;
    //    QTextStream qout(stdout);
    //
    //
    //    qout << "initialRevision = "<< initialRevision<< "finalRevision" << finalRevision<< endl;
    //
    //
    //    
    //    
    //    if (initialRevision == "")
    //        initialInt = 0;
    //    else
    //        initialInt = initialRevision.toInt(initial, 10);
    //
    //
    //    if (finalRevision == "") {
    //        std::cout << "dkfjd1" << endl;
    //        throw (PatoClientException("The log command needs a revision."));
    //    } else {
    //        std::cout << "dkfjd2" << endl;
    //        finalInt = finalRevision.toInt(final, 10);
    //    }
    //


    //    if (address == "") {
    //        throw (PatoClientException("The log command needs an address."));
    //    } else 
    if (username == "") {
        throw (PatoClientException("The log command needs an username."));
    } else if (password == "") {
        throw (PatoClientException("The log command needs a password."));
        //    } else if (initialInt < -1) {
        //        throw (PatoClientException("Invalid initial revision number."));
    } else if (finalInt < -1 || finalInt < initialInt) {
        throw (PatoClientException("Invalid initial revision number."));
    }

    return output;
}

QList<checkoutOutput> PatoClientApi::checkin(QString address, QString username, QString password, QString workspace) throw (PatoClientException) {

    QList<checkoutOutput> output;
    //
    //    if (address == "") {
    //        throw (PatoClientException("The checkin command needs an address."));
    //    } else 
    if (username == "") {
        throw (PatoClientException("The checkin command needs an username."));
    } else if (password == "") {
        throw (PatoClientException("The checkin command needs a password."));
    }
    //    else if (workspace == "") {
    //        throw (PatoClientException("The checkin command needs a workspace."));
    //    }

    return output;
}

QList<addOutput> PatoClientApi::add(QString workspace, QList<QString> files) throw (PatoClientException) {

    QList<addOutput> output;

    if (workspace == "") {
        throw (PatoClientException("The add command needs a workspace."));
    } else if (files.isEmpty()) {
        throw (PatoClientException("The add command needs at least one file to add."));
    }

    return output;
}

QList<statusOutput> PatoClientApi::status(QString workspace) throw (PatoClientException) {

    QList<statusOutput> output;

    if (workspace == "") {
        throw (PatoClientException("The status command needs a workspace."));
    }

    return output;
}

QList<updateOutput> PatoClientApi::update(QString revision, QString address, QString username, QString password, QString workspace) throw (PatoClientException) {


    QList<updateOutput> output;

    //    bool* conversao;
    //    int revisionInt = 0;
    //
    //    revisionInt = revision.toInt(conversao, 10);


//    if (revision == revision.null) {
//        throw (PatoClientException("revision is null!!!"));
//    }

    //    if (revisionInt < -1) {
    //        throw (PatoClientException("Invalid revision number."));
    //    } else

    if (address == "") {
        throw (PatoClientException("The update command needs an address."));
    } else if (username == "") {
        throw (PatoClientException("The update command needs an username."));
    } else if (password == "") {
        throw (PatoClientException("The update command needs a password."));
    }
    
    //    else if (workspace == "") {
    //        throw (PatoClientException("The update command needs a workspace."));
    //    }

    return output;
}

void PatoClientApi::merge(QString path1, QString revision1, QString path2, QString revision2, QString workspace) throw (PatoClientException) {
    if (path1 == "") {
        throw (PatoClientException("The merge command needs a path."));
    } else if (path2 == "") {
        throw (PatoClientException("The merge command needs a path."));
    } else if (workspace == "") {
        throw (PatoClientException("The merge command needs a workspace."));
    } else if (revision1 == "") {
        throw (PatoClientException("The merge command needs a revision."));
    } else if (revision2 == "") {
        throw (PatoClientException("The merge command needs a revision."));
    }

}

QList<updateOutput> PatoClientApi::diff(QString path1, QString revision1, QString path2, QString revision2) throw (PatoClientException) {

    QList<updateOutput> output;

    if (path1 == "") {
        throw (PatoClientException("The diff command needs a path."));
    } else if (path2 == "") {
        throw (PatoClientException("The diff command needs a path."));
    } else if (revision1 == "") {
        throw (PatoClientException("The diff command needs a revision."));
    } else if (revision2 == "") {
        throw (PatoClientException("The diff command needs a revision."));
    }

    return output;
}
