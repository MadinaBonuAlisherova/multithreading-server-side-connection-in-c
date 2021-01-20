drop database if exists travel;
create database travel;


create table category
(
    category_id   serial not null
        constraint category_pk
            primary key,
    category_name varchar(255),
    created_at    timestamp default now(),
    updated_at    timestamp default now()
);

INSERT INTO public.category (category_id, category_name, created_at, updated_at) VALUES (1, 'cat', '2019-12-13 17:29:44.777263', '2019-12-13 17:29:44.777263');
INSERT INTO public.category (category_id, category_name, created_at, updated_at) VALUES (2, 'dog', '2019-12-13 17:29:53.242578', '2019-12-13 17:29:53.242578');
create table requests
(
    req_id           serial not null
        constraint requests_pk
            primary key,
    full_name        varchar(255),
    date_birth       varchar(255),
    gender           varchar(255),
    citizenship      varchar(255),
    category_name    varchar(255),
    service_type     varchar(255),
    doc_serial       varchar(255),
    doc_num          varchar(255),
    card_num         varchar(255),
    card_num_for_pay varchar(20),
    city             varchar(255),
    email            varchar(255),
    zip_code         varchar(255),
    status           varchar(255),
    created_at       timestamp default now(),
    updated_at       timestamp default now()
);


INSERT INTO public.requests (req_id, full_name, date_birth, gender, citizenship, category_name, service_type, doc_serial, doc_num, card_num, card_num_for_pay, city, email, zip_code, status, created_at, updated_at) VALUES (1, 'string', 'string', 'string', 'string', 'string', 'string', 'string', 'string', 'string', 'string', 'string', 'string', 'string', null, '2019-12-20 09:17:37.700220', '2019-12-20 09:17:37.700220');
create table service_type
(
    st_id         serial not null
        constraint service_type_pk
            primary key,
    service_type  varchar(255),
    category_name varchar(255),
    created_at    timestamp default now(),
    updated_at    timestamp default now()
);


INSERT INTO public.service_type (st_id, service_type, category_name, created_at, updated_at) VALUES (1, 'kitten', 'cat', '2019-12-13 18:14:23.693883', '2019-12-13 18:14:23.693883');
INSERT INTO public.service_type (st_id, service_type, category_name, created_at, updated_at) VALUES (2, 'puppy', 'dog', '2019-12-13 18:14:30.548616', '2019-12-13 18:14:30.548616');


create function api_to_pg(procedure_name character varying, json_data character varying) returns text
	language plpgsql
as $$
declare
    --full name, citizenship, data of birth, gender hammasi string
        my_json json;
begin
        if procedure_name is null then
            return json_build_object('status',1,'message','procedure name is null','data',null);
        end if;

        --in this case procedure name is given
        --but body might be not given
        if procedure_name = 'test' then
            return json_build_object('status',0,'message','test message','data',null);
        elsif procedure_name = 'category.all' then
            return categories_all();
        elsif procedure_name = 'service.all' then
            return services_all();
        elsif procedure_name = 'method_doc' then
            return method_doc();
        end if;


        --in this case procedure name is given
        --body should be given
        if procedure_name = 'request.post' then
            if json_data is null then
                return json_build_object('status',1,'message','json_data is null','data',null);
            end if;
            return give_request(json_data);
        elsif procedure_name = 'request.sample' then
            return request_sample();
        elsif procedure_name = '�hange_status' then
            return change_status(json_data);
        else
            return json_build_object('status',1,'message','procedure name is not found','data',null);
        end if;

    end;
$$;



create function categories_all() returns text
	language plpgsql
as $$
declare
        my_json json;
begin
         return json_build_object('status',0,'message','success','data',json_build_object('categories',(select json_agg(t)from ( select category_name from category) t)));
    end;
$$;



create function services_all() returns text
	language plpgsql
as $$
declare
        my_json json;
begin
         return json_build_object('status',0,'message','success','data',json_build_object('services',(select json_agg(t)from ( select s.service_type from service_type s) t)));
    end;
$$;


create function give_request(json_data character varying) returns text
	language plpgsql
as $$
declare
    my_json json;
    full_name_val varchar(255);
    citizenship_val varchar(255);
    date_birth_val varchar(255);
    gender_val varchar(255);
    service_type_val varchar(255);
    category_name_val varchar(255);
    doc_serial_val varchar(255);
	doc_num_val varchar(255);
	card_num_val varchar(255);
	card_num_for_pay_val varchar(255);
	city_val varchar(255);
	email_val varchar(255);
	zip_code_val varchar(255);
begin

    my_json         := (SELECT cast(json_data AS json));
    full_name_val       := (SELECT my_json ->> 'full_name');
    citizenship_val     := (SELECT my_json ->> 'citizenship');
    date_birth_val      := (SELECT my_json ->> 'date_birth');
    gender_val          := (SELECT my_json ->> 'gender');
    service_type_val    := (SELECT my_json ->> 'service_type');
    category_name_val   := (SELECT my_json ->> 'category_name');

    doc_serial_val := (SELECT my_json ->> 'doc_serial');
    doc_num_val := (SELECT my_json ->> 'doc_num');
    card_num_val := (SELECT my_json ->> 'card_num');
    card_num_for_pay_val := (SELECT my_json ->> 'card_num_for_pay');
    city_val := (SELECT my_json ->> 'city');
    email_val := (SELECT my_json ->> 'email');
    zip_code_val := (SELECT my_json ->> 'zip_code');


    insert into requests (full_name, date_birth, gender, citizenship, category_name, service_type,doc_serial,doc_num,card_num,card_num_for_pay,city,email,zip_code)
    values (full_name_val,date_birth_val,gender_val,citizenship_val,category_name_val,service_type_val,doc_serial_val,doc_num_val,card_num_val,card_num_for_pay_val,city_val,email_val,zip_code_val);
    return json_build_object('status',0,'message','success','data',null);
    end;
$$;



create function method_doc() returns text
	language plpgsql
as $$
declare
        my_json json;
begin
         return json_build_object('status',0,'message','success','data',json_build_object('method_doc',
             json_build_object('test',null,'category.all',null,'service.all',null,'method_doc',null,'request.sample',null,'request.post','json','change_status','json')));
    end;
$$;



create function change_status(json_data character varying) returns text
	language plpgsql
as $$
declare
    my_json json;
    request_id integer;
    status_val varchar(255);
begin

    my_json     := (SELECT cast(json_data AS json));
    request_id  := (SELECT my_json ->> 'request_id');
    status_val      := (SELECT my_json ->> 'status');

    update requests set status = status_val where req_id = request_id;
    return json_build_object('status',0,'message','success','data',null);
    end;
$$;



create function request_sample() returns text
	language plpgsql
as $$
declare
begin
        return json_build_object('status',0,'message','success','data',
                json_build_object('sample',
                    json_build_object(
                        'full_name','string',
                        'citizenship','string',
                        'date_birth','string',
                        'gender','string',
                        'service_type','string',
                        'category_name','string',
                        'doc_serial','string',
                        'doc_num','string',
                        'card_num','string',
                        'card_num_for_pay','string',
                        'city','string',
                        'email','string',
                        'zip_code','string'
                        )));
    end;
$$;


