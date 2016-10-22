#include <QSqlDatabase>

class DbManager
{
public:
	DbManager(const QString& path);
	bool addNote();
	bool deleteNote();
	void showNote();
	~DbManager();
private:
	QSqlDatabase m_db;
};