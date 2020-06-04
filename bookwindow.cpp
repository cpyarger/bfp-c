/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "bookwindow.h"
#include "bookdelegate.h"
#include "initdb.h"

#include <QtSql>

BookWindow::BookWindow()
{
    ui.setupUi(this);
    ui.groupBox->hide();
    if (!QSqlDatabase::drivers().contains("QSQLITE"))
        QMessageBox::critical(
                    this,
                    "Unable to load database",
                    "This demo needs the SQLITE driver"
                    );

    // Initialize the database:
    QSqlError err = initDb();
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    // Create the data model:
    model = new QSqlRelationalTableModel(ui.TableView);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("folders");
/*
    // Remember the indexes of the columns:
    authorIdx = model->fieldIndex("author");
    genreIdx = model->fieldIndex("genre");

    // Set the relations to the other database tables:
    model->setRelation(authorIdx, QSqlRelation("authors", "id", "name"));
    model->setRelation(genreIdx, QSqlRelation("genres", "id", "name"));

    // Set the localized header captions:
    model->setHeaderData(authorIdx, Qt::Horizontal, tr("Author Name"));
    model->setHeaderData(genreIdx, Qt::Horizontal, tr("Genre"));
    model->setHeaderData(model->fieldIndex("title"),
                         Qt::Horizontal, tr("Title"));
    model->setHeaderData(model->fieldIndex("year"), Qt::Horizontal, tr("Year"));
    model->setHeaderData(model->fieldIndex("rating"),
                         Qt::Horizontal, tr("Rating"));
*/
    // Populate the model:
    if (!model->select()) {
        showError(model->lastError());
        return;
    }

    // Set the model and hide the ID column:
    ui.TableView->setModel(model);
    ui.TableView->setItemDelegate(new BookDelegate(ui.TableView));
    ui.TableView->setColumnHidden(model->fieldIndex("id"), true);
    ui.TableView->setSelectionMode(QAbstractItemView::SingleSelection);
    //Hide Extra Columns

    model->setHeaderData(1, Qt::Horizontal, tr("Folder"));
    model->setHeaderData(3, Qt::Horizontal, tr("Enabled?"));
    ui.TableView->setColumnHidden(model->fieldIndex("copy_to_directory"), true);
    //ui.TableView->setColumnHidden(model->fieldIndex("folder_is_active"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("alias"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("process_backend_copy"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("process_backend_ftp"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("process_backend_email"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("ftp_server"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("ftp_folder"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("ftp_username"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("ftp_password"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("email_to"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("process_edi"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("convert_to_format"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("calculate_upc_check_digit"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("include_a_records"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("include_c_records"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("include_headers"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("filter_ampersand"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("tweak_edi"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("split_edi"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("pad_a_records"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("a_record_padding"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("ftp_port"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("email_subject_line"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("force_edi_validation"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("append_a_records"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("a_record_append_text"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("force_txt_file_ext"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("invoice_date_offset"), true);
    ui.TableView->setColumnHidden(model->fieldIndex("id"), true);



/*
    // Initialize the Author combo box:
    ui.authorEdit->setModel(model->relationModel(authorIdx));
    ui.authorEdit->setModelColumn(
                model->relationModel(authorIdx)->fieldIndex("name"));

    ui.genreEdit->setModel(model->relationModel(genreIdx));
    ui.genreEdit->setModelColumn(
                model->relationModel(genreIdx)->fieldIndex("name"));

    // Lock and prohibit resizing of the width of the rating column:
    ui.TableView->horizontalHeader()->setSectionResizeMode(
                model->fieldIndex("rating"),
                QHeaderView::ResizeToContents);
*/
    QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->setItemDelegate(new BookDelegate(this));
    //Set up FTP edit Mappings
    mapper->addMapping(ui.cb_ftp_backend, model->fieldIndex("process_backend_ftp"));
    mapper->addMapping(ui.txt_ftp_port, model->fieldIndex("ftp_port"));
    mapper->addMapping(ui.txt_ftp_password, model->fieldIndex("ftp_password"));
    mapper->addMapping(ui.txt_ftp_username, model->fieldIndex("ftp_username"));
    mapper->addMapping(ui.txt_ftp_folder, model->fieldIndex("ftp_folder"));
    mapper->addMapping(ui.txt_ftp_server, model->fieldIndex("ftp_server"));

    //Setup Email Edit Mappings
    mapper->addMapping(ui.cb_email_backend, model->fieldIndex("process_backend_email"));
    mapper->addMapping(ui.txt_email_address, model->fieldIndex("email_to"));
    mapper->addMapping(ui.txt_email_subject, model->fieldIndex("email_subject_line"));

    //Setup Copy Edit Mappings
    mapper->addMapping(ui.cb_copy_backend, model->fieldIndex("process_backend_copy"));

    //Setup folder Alias Mapping
    mapper->addMapping(ui.txt_folder_alias, model->fieldIndex("alias"));

/*
    mapper->addMapping(ui.titleEdit, model->fieldIndex("title"));
    mapper->addMapping(ui.yearEdit, model->fieldIndex("year"));
    mapper->addMapping(ui.authorEdit, authorIdx);
    mapper->addMapping(ui.genreEdit, genreIdx);
    mapper->addMapping(ui.ratingEdit, model->fieldIndex("rating"));
*/
    connect(ui.TableView->selectionModel(),
            &QItemSelectionModel::currentRowChanged,
            mapper,
            &QDataWidgetMapper::setCurrentModelIndex
            );

    ui.TableView->setCurrentIndex(model->index(0, 0));
    createMenuBar();
}

void BookWindow::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}

void BookWindow::createMenuBar()
{
    QAction *quitAction = new QAction(tr("&Quit"), this);
    QAction *aboutAction = new QAction(tr("&About"), this);
    QAction *aboutQtAction = new QAction(tr("&About Qt"), this);

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(quitAction);

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);

    connect(quitAction, &QAction::triggered, this, &BookWindow::close);
    connect(aboutAction, &QAction::triggered, this, &BookWindow::about);
    connect(aboutQtAction, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void BookWindow::about()
{
    QMessageBox::about(this, tr("About Books"),
            tr("<p>The <b>Books</b> example shows how to use Qt SQL classes "
               "with a model/view framework."));
}
