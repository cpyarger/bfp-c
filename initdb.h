/****************************************************************************
**
** Copyright (C) 2020 The Qt Company Ltd.
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

#ifndef INITDB_H
#define INITDB_H

#include <QtSql>
//QString appname = "Batch File Sender";
//QString config_folder = "./"+appname;
//QString database_path = config_folder+ "/folders.db";
QString database_path = "./folders.db";
void addSettings(QSqlQuery &q,int id ,
                 const QVariant &enable_email,
                 const QString &email_address,
                 const QString &email_username,
                 const QString &email_password,
                 const QString &email_smtp_server,
                 int smtp_port,int backup_counter,
                 int backup_counter_maximum,
                 const QVariant &enable_interval_backups){
    q.addBindValue(id);
    q.addBindValue(enable_email);
    q.addBindValue(email_address);
    q.addBindValue(email_username);
    q.addBindValue(email_password);
    q.addBindValue(email_smtp_server);
    q.addBindValue(smtp_port);
    q.addBindValue(backup_counter);
    q.addBindValue(backup_counter_maximum);
    q.addBindValue(enable_interval_backups);
    q.exec();
}

QVariant addVersion(QSqlQuery &q,int id,
                    const QString &version,
                    const QString &os)
{
    q.addBindValue(id);
    q.addBindValue(version);
    q.addBindValue(os);
    q.exec();
    return q.lastInsertId();
}

QVariant addProcessedFiles(QSqlQuery &q,
                           int id,
                           const QString &file_name,
                           const QString &file_checksum,
                           const QString &copy_destination,
                           const QString &ftp_destination,
                           const QString &email_destination,
                           const QVariant &resend_flag,
                           int folder_id,
                           const QString &folder_alias,
                           QDate sent_date_time){
    q.addBindValue(id);
    q.addBindValue(file_name);
    q.addBindValue(file_checksum);
    q.addBindValue(copy_destination);
    q.addBindValue(ftp_destination);
    q.addBindValue(email_destination);
    q.addBindValue(resend_flag);
    q.addBindValue(folder_id);
    q.addBindValue(folder_alias);
    q.addBindValue(sent_date_time);
    q.exec();
    return q.lastInsertId();
}

QVariant addAdministrative(QSqlQuery &q,
                           int id,
                           const QString &folder_is_active,
                           const QString &copy_to_directory,
                           const QString &process_edi ,
                           const QString &convert_to_format ,
                           const QString &calculate_upc_check_digit ,
                           const QString &include_a_records ,
                           const QString &include_c_records ,
                           const QString &include_headers ,
                           const QString &filter_ampersand,
                           const QVariant &tweak_edi,
                           const QString &pad_a_records,
                           const QString &a_record_padding,
                           const QString &reporting_email,
                           const QString &folder_name,
                           const QString &alias,
                           const QString &report_email_destination,
                           const QVariant &process_backend_copy,
                           const QVariant &process_backend_ftp,
                           const QVariant &process_backend_email,
                           const QString &ftp_server ,
                           const QString &ftp_folder ,
                           const QString &ftp_username,
                           const QString &ftp_password,
                           const QString &email_to,
                           const QString &logs_directory,
                           const QString &edi_converter_scratch_folder,
                           const QString &errors_folder ,
                           const QString &enable_reporting,
                           const QString &report_printing_fallback ,
                           int ftp_port ,
                           const QString &email_subject_line ,
                           const QString &single_add_folder_prior,
                           const QString &batch_add_folder_prior,
                           const QString &export_processed_folder_prior,
                           const QVariant &report_edi_errors ,
                           const QVariant &split_edi ,
                           const QVariant &force_edi_validation ,
                           const QString &append_a_records ,
                           const QString &a_record_append_text,
                           const QString &force_txt_file_ext ,
                           int invoice_date_offset)
{
    q.addBindValue(id);
    q.addBindValue(folder_is_active);
    q.addBindValue(copy_to_directory);
    q.addBindValue(process_edi );
    q.addBindValue(convert_to_format );
    q.addBindValue(calculate_upc_check_digit );
    q.addBindValue(include_a_records );
    q.addBindValue(include_c_records );
    q.addBindValue(include_headers );
    q.addBindValue(filter_ampersand);
    q.addBindValue(tweak_edi);
    q.addBindValue(pad_a_records);
    q.addBindValue(a_record_padding);
    q.addBindValue(reporting_email);
    q.addBindValue(folder_name);
    q.addBindValue(alias);
    q.addBindValue(report_email_destination);
    q.addBindValue(process_backend_copy);
    q.addBindValue(process_backend_ftp);
    q.addBindValue(process_backend_email);
    q.addBindValue(ftp_server );
    q.addBindValue(ftp_folder );
    q.addBindValue(ftp_username);
    q.addBindValue(ftp_password);
    q.addBindValue(email_to);
    q.addBindValue(logs_directory);
    q.addBindValue(edi_converter_scratch_folder);
    q.addBindValue(errors_folder );
    q.addBindValue(enable_reporting);
    q.addBindValue(report_printing_fallback );
    q.addBindValue(ftp_port );
    q.addBindValue(email_subject_line );
    q.addBindValue(single_add_folder_prior);
    q.addBindValue(batch_add_folder_prior);
    q.addBindValue(export_processed_folder_prior);
    q.addBindValue(report_edi_errors );
    q.addBindValue(split_edi );
    q.addBindValue(force_edi_validation );
    q.addBindValue(append_a_records );
    q.addBindValue(a_record_append_text);
    q.addBindValue(force_txt_file_ext );
    q.addBindValue(invoice_date_offset);
    q.exec();
    return q.lastInsertId();
}
QVariant addFolders(QSqlQuery &q,
                    int id,
                    const QString &folder_name,
                    const QString &copy_to_directory,
                    const QString &folder_is_active,
                    const QString &alias,
                    const QVariant &process_backend_copy,
                    const QVariant &process_backend_ftp,
                    const QVariant &process_backend_email,
                    const QString &ftp_server,
                    const QString &ftp_folder,
                    const QString &ftp_username,
                    const QString &ftp_password,
                    const QString &email_to,
                    const QString &	process_edi,
                    const QString &convert_to_format,
                    const QString &calculate_upc_check_digit,
                    const QString &include_a_records,
                    const QString &include_c_records,
                    const QString &include_headers,
                    const QString &filter_ampersand,
                    const QVariant &tweak_edi,
                    const QVariant &split_edi,
                    const QString &pad_a_records,
                    const QString &a_record_padding,
                    int ftp_port,
                    const QString &email_subject_line,
                    const QVariant &force_edi_validation,
                    const QString &append_a_records,
                    const QString &a_record_append_,
                    const QString &force_txt_file_ext,
                    int invoice_date_offset)
{
    q.addBindValue(id);
    q.addBindValue(folder_name);
    q.addBindValue(copy_to_directory);
    q.addBindValue(folder_is_active);
    q.addBindValue(alias);
    q.addBindValue(process_backend_copy);
    q.addBindValue(process_backend_ftp);
    q.addBindValue(process_backend_email);
    q.addBindValue(ftp_server);
    q.addBindValue(ftp_folder);
    q.addBindValue(ftp_username);
    q.addBindValue(ftp_password);
    q.addBindValue(email_to);
    q.addBindValue(process_edi);
    q.addBindValue(convert_to_format);
    q.addBindValue(calculate_upc_check_digit);
    q.addBindValue(include_a_records);
    q.addBindValue(include_c_records);
    q.addBindValue(include_headers);
    q.addBindValue(filter_ampersand);
    q.addBindValue(tweak_edi);
    q.addBindValue(split_edi);
    q.addBindValue(pad_a_records);
    q.addBindValue(a_record_padding);
    q.addBindValue(ftp_port);
    q.addBindValue(email_subject_line);
    q.addBindValue(force_edi_validation);
    q.addBindValue(append_a_records);
    q.addBindValue(a_record_append_);
    q.addBindValue(force_txt_file_ext);
    q.addBindValue(invoice_date_offset);
    q.exec();
    return q.lastInsertId();
}


const auto SETTINGS_SQL = QLatin1String(R"(
                                        CREATE TABLE settings (
                                        id INTEGER NOT NULL,
                                        enable_email BOOLEAN,
                                        email_address TEXT,
                                        email_username TEXT,
                                        email_password TEXT,
                                        email_smtp_server TEXT,
                                        smtp_port BIGINT,
                                        backup_counter BIGINT,
                                        backup_counter_maximum BIGINT,
                                        enable_interval_backups BOOLEAN,
                                        PRIMARY KEY (id),
                                        CHECK (enable_email IN (0, 1)),
                                        CHECK (enable_interval_backups IN (0, 1))
                                        )
                                        )");

const auto VERSION_SQL =  QLatin1String(R"(
                                        CREATE TABLE version (
                                        id INTEGER NOT NULL,
                                        version TEXT,
                                        os TEXT,
                                        PRIMARY KEY (id)
                                        )
                                        )");
const auto ADMINISTRATIVE_SQL =  QLatin1String(R"(CREATE TABLE administrative (
                                               id INTEGER NOT NULL,
                                               folder_is_active TEXT,
                                               copy_to_directory TEXT,
                                               process_edi TEXT,
                                               convert_to_format TEXT,
                                               calculate_upc_check_digit TEXT,
                                               include_a_records TEXT,
                                               include_c_records TEXT,
                                               include_headers TEXT,
                                               filter_ampersand TEXT,
                                               tweak_edi BOOLEAN,
                                               pad_a_records TEXT,
                                               a_record_padding TEXT,
                                               reporting_email TEXT,
                                               folder_name TEXT,
                                               alias TEXT,
                                               report_email_destination TEXT,
                                               process_backend_copy BOOLEAN,
                                               process_backend_ftp BOOLEAN,
                                               process_backend_email BOOLEAN,
                                               ftp_server TEXT,
                                               ftp_folder TEXT,
                                               ftp_username TEXT,
                                               ftp_password TEXT,
                                               email_to TEXT,
                                               logs_directory TEXT,
                                               edi_converter_scratch_folder TEXT,
                                               errors_folder TEXT,
                                               enable_reporting TEXT,
                                               report_printing_fallback TEXT,
                                               ftp_port BIGINT,
                                               email_subject_line TEXT,
                                               single_add_folder_prior TEXT,
                                               batch_add_folder_prior TEXT,
                                               export_processed_folder_prior TEXT,
                                               report_edi_errors BOOLEAN,
                                               split_edi BOOLEAN,
                                               force_edi_validation BOOLEAN,
                                               append_a_records TEXT,
                                               a_record_append_text TEXT,
                                               force_txt_file_ext TEXT,
                                               invoice_date_offset BIGINT,
                                               PRIMARY KEY (id),
                                               CHECK (tweak_edi IN (0, 1)),
                                               CHECK (process_backend_copy IN (0, 1)),
                                               CHECK (process_backend_ftp IN (0, 1)),
                                               CHECK (process_backend_email IN (0, 1)),
                                               CHECK (report_edi_errors IN (0, 1)),
                                               CHECK (split_edi IN (0, 1)),
                                               CHECK (force_edi_validation IN (0, 1))
                                               )
                                               )");
const auto PROCESSED_FILES_SQL =  QLatin1String(R"(CREATE TABLE processed_files (
                                                id INTEGER NOT NULL,
                                                file_name VARCHAR,
                                                file_checksum VARCHAR,
                                                copy_destination VARCHAR,
                                                ftp_destination VARCHAR,
                                                email_destination VARCHAR,
                                                resend_flag BOOLEAN,
                                                folder_id INTEGER,
                                                folder_alias TEXT,
                                                sent_date_time DATETIME,
                                                PRIMARY KEY (id)
                                                )
                                                )");

const auto Folders_SQL = QLatin1String(R"(
                                       CREATE TABLE folders (
                                           id INTEGER NOT NULL,
                                           folder_name TEXT,
                                           copy_to_directory TEXT,
                                           folder_is_active TEXT,
                                           alias TEXT,
                                           process_backend_copy BOOLEAN,
                                           process_backend_ftp BOOLEAN,
                                           process_backend_email BOOLEAN,
                                           ftp_server TEXT,
                                           ftp_folder TEXT,
                                           ftp_username TEXT,
                                           ftp_password TEXT,
                                           email_to TEXT,
                                           process_edi TEXT,
                                           convert_to_format TEXT,
                                           calculate_upc_check_digit TEXT,
                                           include_a_records TEXT,
                                           include_c_records TEXT,
                                           include_headers TEXT,
                                           filter_ampersand TEXT,
                                           tweak_edi BOOLEAN,
                                           split_edi BOOLEAN,
                                           pad_a_records TEXT,
                                           a_record_padding TEXT,
                                           ftp_port BIGINT,
                                           email_subject_line TEXT,
                                           force_edi_validation BOOLEAN,
                                           append_a_records TEXT,
                                           a_record_append_text TEXT,
                                           force_txt_file_ext TEXT,
                                           invoice_date_offset BIGINT,
                                           PRIMARY KEY (id),
                                           CHECK (process_backend_copy IN (0, 1)),
                                           CHECK (process_backend_ftp IN (0, 1)),
                                           CHECK (process_backend_email IN (0, 1)),
                                           CHECK (tweak_edi IN (0, 1)),
                                           CHECK (split_edi IN (0, 1)),
                                           CHECK (force_edi_validation IN (0, 1))
                                       )
    )");
/*
const auto INSERT_AUTHOR_SQL = QLatin1String(R"(
    insert into authors(name, birthdate) values(?, ?)
    )");

const auto INSERT_BOOK_SQL = QLatin1String(R"(
    insert into books(title, year, author, genre, rating)
                      values(?, ?, ?, ?, ?)
    )");

const auto INSERT_GENRE_SQL = QLatin1String(R"(
    insert into genres(name) values(?)
    )");
*/
QSqlError initDb()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(database_path);

    if (!db.open())
        return db.lastError();

    QStringList tables = db.tables();
    if (tables.contains("folders", Qt::CaseInsensitive)
        && tables.contains("administrative", Qt::CaseInsensitive)
        && tables.contains("settings", Qt::CaseInsensitive)
        && tables.contains("processed_files", Qt::CaseInsensitive)
        && tables.contains("version", Qt::CaseInsensitive))
        return QSqlError();




    QSqlQuery q;
    if (!q.exec(SETTINGS_SQL))
        return q.lastError();
    if (!q.exec(ADMINISTRATIVE_SQL))
        return q.lastError();
    if (!q.exec(PROCESSED_FILES_SQL))
        return q.lastError();
    if (!q.exec(Folders_SQL))
        return q.lastError();
    if (!q.exec(VERSION_SQL))
        return q.lastError();
/*

    if (!q.prepare(INSERT_AUTHOR_SQL))
        return q.lastError();
    QVariant asimovId = addAuthor(q, QLatin1String("Isaac Asimov"), QDate(1920, 2, 1));
    QVariant greeneId = addAuthor(q, QLatin1String("Graham Greene"), QDate(1904, 10, 2));
    QVariant pratchettId = addAuthor(q, QLatin1String("Terry Pratchett"), QDate(1948, 4, 28));

    if (!q.prepare(INSERT_GENRE_SQL))
        return q.lastError();
    QVariant sfiction = addGenre(q, QLatin1String("Science Fiction"));
    QVariant fiction = addGenre(q, QLatin1String("Fiction"));
    QVariant fantasy = addGenre(q, QLatin1String("Fantasy"));

    if (!q.prepare(INSERT_BOOK_SQL))
        return q.lastError();
    addBook(q, QLatin1String("Foundation"), 1951, asimovId, sfiction, 3);
    addBook(q, QLatin1String("Foundation and Empire"), 1952, asimovId, sfiction, 4);
    addBook(q, QLatin1String("Second Foundation"), 1953, asimovId, sfiction, 3);
    addBook(q, QLatin1String("Foundation's Edge"), 1982, asimovId, sfiction, 3);
    addBook(q, QLatin1String("Foundation and Earth"), 1986, asimovId, sfiction, 4);
    addBook(q, QLatin1String("Prelude to Foundation"), 1988, asimovId, sfiction, 3);
    addBook(q, QLatin1String("Forward the Foundation"), 1993, asimovId, sfiction, 3);
    addBook(q, QLatin1String("The Power and the Glory"), 1940, greeneId, fiction, 4);
    addBook(q, QLatin1String("The Third Man"), 1950, greeneId, fiction, 5);
    addBook(q, QLatin1String("Our Man in Havana"), 1958, greeneId, fiction, 4);
    addBook(q, QLatin1String("Guards! Guards!"), 1989, pratchettId, fantasy, 3);
    addBook(q, QLatin1String("Night Watch"), 2002, pratchettId, fantasy, 3);
    addBook(q, QLatin1String("Going Postal"), 2004, pratchettId, fantasy, 3);
*/
    return QSqlError();

}

#endif
