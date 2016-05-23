#include <QChart>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QApplication>
#include <QMainWindow>

QT_CHARTS_USE_NAMESPACE

QBarSeries* createSeries()
{
	QBarSet *set0 = new QBarSet("Jane");
	QBarSet *set1 = new QBarSet("John");
	QBarSet *set2 = new QBarSet("Axel");
	QBarSet *set3 = new QBarSet("Mary");
	QBarSet *set4 = new QBarSet("Samantha");

	*set0 << 1 << 2 << 3 << 4 << 5 << 6;
	*set1 << 5 << 0 << 0 << 4 << 0 << 7;
	*set2 << 3 << 5 << 8 << 13 << 8 << 5;
	*set3 << 5 << 6 << 7 << 3 << 4 << 5;
	*set4 << 9 << 7 << 5 << 3 << 1 << 2;

	QBarSeries *series = new QBarSeries();
	series->append(set0);
	series->append(set1);
	series->append(set2);
	series->append(set3);
	series->append(set4);
	return series;
}

QBarCategoryAxis* createCategories()
{
	QStringList categories;
   categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
   QBarCategoryAxis *axis = new QBarCategoryAxis();
	axis->append( categories);
	return axis;
}

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	QMainWindow mw;

	QBarSeries* series = createSeries();
	QChart * chart = new QChart();
	chart->addSeries( series);
   chart->setTitle("Simple barchart example");
   chart->setAnimationOptions(QChart::SeriesAnimations);
	chart->createDefaultAxes();
	chart->setAxisX( createCategories(), series);
	chart->legend()->setVisible( true);
	chart->legend()->setAlignment( Qt::AlignBottom);


	// Chart view
	QChartView *chartView = new QChartView( chart);
	chartView->setRenderHint( QPainter::Antialiasing);

	mw.setCentralWidget( chartView);
	mw.resize( 420, 300);
	mw.show ();

	return app.exec();
}
